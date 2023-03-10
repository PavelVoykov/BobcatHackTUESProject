package com.example.buttonclickapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        Button buttonContacts = findViewById(R.id.ListOfContactsBtn);

        buttonContacts.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                Intent intent=new Intent(MainActivity.this,ListOfContacts.class);
                startActivity(intent);
            }
        });

        Button buttonNotifications = findViewById(R.id.NotificationsBtn);

        buttonNotifications.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                Intent intent=new Intent(MainActivity.this,Notifications.class);
                startActivity(intent);
            }
        });


    }
}