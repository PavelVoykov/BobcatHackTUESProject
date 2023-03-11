package com.example.helpm8;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.navigation.fragment.NavHostFragment;

import com.example.helpm8.databinding.FragmentSecondBinding;

public class SecondFragment extends Fragment {

    private FragmentSecondBinding binding;
    MainActivity m = new MainActivity();
    @Override
    public View onCreateView(
            LayoutInflater inflater, ViewGroup container,
            Bundle savedInstanceState
    ) {

        binding = FragmentSecondBinding.inflate(inflater, container, false);

        return binding.getRoot();

    }

    public void onViewCreated(@NonNull View view, Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        if(m.names[0] != null) {
            binding.buttonContact1.setText(m.names[0] +": "+ Integer.toString(m.numbers[0]));
        }
        if(m.names[1] != null) {
            binding.buttonContact2.setText(m.names[1] +": "+ Integer.toString(m.numbers[1]));
        }
        if(m.names[2] != null) {
            binding.buttonContact3.setText(m.names[2] +": "+ Integer.toString(m.numbers[2]));
        }
        if(m.names[3] != null) {
            binding.buttonContact4.setText(m.names[3] +": "+ Integer.toString(m.numbers[3]));
        }
        if(m.names[4] != null) {
            binding.buttonContact5.setText(m.names[4] +": "+ Integer.toString(m.numbers[4]));
        }
        binding.buttonPrev.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                NavHostFragment.findNavController(SecondFragment.this)
                        .navigate(R.id.action_SecondFragment_to_FirstFragment);
            }
        });
        binding.buttonContact1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                m.currEdit = 0;
                NavHostFragment.findNavController(SecondFragment.this)
                        .navigate(R.id.action_SecondFragment_to_ThirdFragment);
            }
        });
        binding.buttonContact2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                m.currEdit = 1;
                NavHostFragment.findNavController(SecondFragment.this)
                        .navigate(R.id.action_SecondFragment_to_ThirdFragment);
            }
        });
        binding.buttonContact3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                m.currEdit = 2;
                NavHostFragment.findNavController(SecondFragment.this)
                        .navigate(R.id.action_SecondFragment_to_ThirdFragment);
            }
        });
        binding.buttonContact4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                m.currEdit = 3;
                NavHostFragment.findNavController(SecondFragment.this)
                        .navigate(R.id.action_SecondFragment_to_ThirdFragment);
            }
        });
        binding.buttonContact5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                m.currEdit = 4;
                NavHostFragment.findNavController(SecondFragment.this)
                        .navigate(R.id.action_SecondFragment_to_ThirdFragment);
            }
        });
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        binding = null;
    }

}