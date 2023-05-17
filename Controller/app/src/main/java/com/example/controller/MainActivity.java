package com.example.controller;

import android.graphics.Color;
import android.os.AsyncTask;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Spinner;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Context;
import android.content.pm.ActivityInfo;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.TextView;

import java.util.Collections;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.Socket;
import java.net.UnknownHostException;

public class MainActivity extends AppCompatActivity {
    public static int x, y, z;
    public static boolean allowed=false;
    TextView textX, textY, textZ, textView1, textView2, textView3;;
    EditText adressEntry;
    Button sendAdressButton;
    ImageView refresh;
    SensorManager sensorManager;
    Sensor sensor;

    private Socket socket;
    private BufferedReader input;
    private PrintWriter output;

    private String SERVER_IP; // Linux IP Adress
    private int SERVER_PORT; // Port used in the server

    boolean push;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        sensor = sensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE);

        textX = findViewById(R.id.X);
        textY = findViewById(R.id.Y);
        textZ = findViewById(R.id.Z);

        textView1 = findViewById(R.id.textView1);
        textView2 = findViewById(R.id.textView2);
        textView3 = findViewById(R.id.textView3);
        textView1.setVisibility(View.VISIBLE);
        adressEntry = findViewById(R.id.entry1);
        sendAdressButton = findViewById(R.id.button);

        refresh = findViewById(R.id.refresh);

        Refresh();

        refresh.setOnClickListener(view -> Refresh());



        sendAdressButton.setOnClickListener(view -> {
            SERVER_IP = adressEntry.getText().toString();
            if (isValidIPv4(SERVER_IP)) {
                textView1.setText("Valid IP Address");
                sendData();
            } else {
                wrongIP();
            }
        });
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_UNSPECIFIED);
    }

    private void wrongIP() {
        textView1.setText("The IP address is invalid");
        new Thread(() -> {
            try {
                Thread.sleep(2500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            runOnUiThread(() -> {
                textView1.setText("Write the IP address of the server");
            });
        }).start();
    }
    private void Refresh(){
        new Thread(this::getNetworkIPs).start();
        push = false;
        SERVER_PORT = 5001;
        SERVER_IP = "";
    }

    private void sendData() {
        new Thread(() -> {
            try {
                socket = new Socket(SERVER_IP, SERVER_PORT);
                input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                output = new PrintWriter(socket.getOutputStream(), true);
                while (true){
                    if(x != 0 || y!=0) {
                        String message = x + "," + y+ "\n" ;
                        output.printf(message);
                        Log.d("Send", message);
                    }
                }


                /*
                String response = input.readLine();
                Log.d("answer", response);*/
                //runOnUiThread(() -> textView3.setText("Answer: " + response));

                //socket.close();
            } catch (IOException e) {
                runOnUiThread(() -> textView3.setText("It is not working"));
                e.printStackTrace();
            }
    }).start();
    }

    private static boolean isValidIPv4(String ip) {
        Pattern pattern = Pattern.compile("^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\." +
                "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\." +
                "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\." +
                "([01]?\\d\\d?|2[0-4]\\d|25[0-5])$");
        Matcher matcher = pattern.matcher(ip);
        return matcher.matches();
    }
    public void getNetworkIPs() {

        byte[] ip = new byte[4];
        final StringLinkedList list = new StringLinkedList();
        try {
            List<NetworkInterface> interfaces = Collections.list(NetworkInterface.getNetworkInterfaces());
            for (NetworkInterface intf : interfaces) {
                List<InetAddress> addrs = Collections.list(intf.getInetAddresses());
                for (InetAddress addr : addrs) {
                    if (!addr.isLoopbackAddress() && addr instanceof Inet4Address) {
                        //ip = ipv4ToBytes(addr.getHostAddress());
                        Log.d("Host Address", addr.getHostAddress());
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
            return;     // exit method, otherwise "ip might not have been initialized"
        }
        final byte[] ipFinal = ip;

        try {
            String ipID = InetAddress.getByAddress(ipFinal).toString().substring(1);
            ipID = ipID.substring(0, ipID.lastIndexOf(".")+1) + 'X';
            adressEntry.setText(ipID);
        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        }
    }

    public void onResume(){
        super.onResume();
        sensorManager.registerListener(gyroListener,sensor,SensorManager.SENSOR_DELAY_NORMAL);
    }
    public void onStop(){
        super.onStop();
        sensorManager.unregisterListener(gyroListener);
    }
    public SensorEventListener gyroListener = new SensorEventListener() {
        @Override
        public void onSensorChanged(SensorEvent sensorEvent) {
            x = (int)sensorEvent.values[0];
            y = (int)sensorEvent.values[1];
            z = (int)sensorEvent.values[2];

            textX.setText("X: " + (int) x);
            textY.setText("Y: " + (int) y);
            textZ.setText("Z: " + (int) z);
            String message = x+", "+y+", "+z;
            //output.printf(message);
        }
        @Override
        public void onAccuracyChanged(Sensor sensor, int i) {
        }
    };

}