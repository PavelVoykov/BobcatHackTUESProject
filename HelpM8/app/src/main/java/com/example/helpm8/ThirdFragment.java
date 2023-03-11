package com.example.helpm8;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.navigation.fragment.NavHostFragment;

import com.example.helpm8.databinding.FragmentSecondBinding;
import com.example.helpm8.databinding.FragmentThirdBinding;

public class ThirdFragment extends Fragment {

    private FragmentThirdBinding binding;
    MainActivity m = new MainActivity();
    EditText Name;
    EditText Number;
    Button Submit;
    String NameS;
    int PNumberS;


    @Override
    public View onCreateView(
            LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState
    ) {
        View view =  inflater.inflate(R.layout.fragment_third, container, false);
        binding = FragmentThirdBinding.inflate(inflater, container, false);
        return binding.getRoot();

    }

    public void onViewCreated(@NonNull View view, Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        binding.buttonFirst.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                NavHostFragment.findNavController(ThirdFragment.this)
                        .navigate(R.id.action_ThirdFragment_to_SecondFragment);
            }
        });
        Name = (EditText) view.findViewById(R.id.name);
        Number = (EditText) view.findViewById(R.id.phone);
        Submit = (Button) view.findViewById(R.id.submit);

        binding.submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                m.names[m.currEdit] = Name.getText().toString();
                m.numbers[m.currEdit] = Integer.valueOf(Number.getText().toString());
                System.out.println(m.currEdit);
                System.out.println(m.names[m.currEdit]);
                System.out.println(m.numbers[m.currEdit]);

            }
        });


    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        binding = null;
    }

}