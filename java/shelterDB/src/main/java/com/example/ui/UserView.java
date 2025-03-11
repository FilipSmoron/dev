package com.example.ui;

import com.example.dao.AnimalShelterDAO;
import com.example.model.Animal;
import com.example.model.AnimalShelter;

import javax.swing.*;
import java.util.List;

public class UserView extends JFrame {
    private final AnimalShelterDAO shelterDAO = new AnimalShelterDAO();

    public UserView() {
        setTitle("User Panel");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        JPanel panel = new JPanel();
        JButton showSheltersButton = new JButton("Show Shelters");

        showSheltersButton.addActionListener(e -> {
            List<AnimalShelter> shelters = shelterDAO.getAll();
            StringBuilder shelterInfo = new StringBuilder();

            for (AnimalShelter shelter : shelters) {
                shelterInfo.append("Shelter: ").append(shelter.getName()).append("\n");
                for (Animal animal : shelter.getAnimals()) {
                    shelterInfo.append("- ").append(animal.getName()).append("\n");
                }
                shelterInfo.append("\n");
            }

            JOptionPane.showMessageDialog(null, shelterInfo.toString());
        });

        panel.add(showSheltersButton);
        add(panel);
    }
}
