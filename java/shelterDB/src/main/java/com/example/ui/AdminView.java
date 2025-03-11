package com.example.ui;

import com.example.controller.ShelterController;
import com.example.controller.RatingController;
import com.example.model.AnimalShelter;
import com.example.model.Rating;

import javax.swing.*;
import java.util.List;

public class AdminView extends JFrame {
    private final ShelterController shelterController = new ShelterController();
    private final RatingController ratingController = new RatingController();

    public AdminView() {
        setTitle("Admin Panel");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        JPanel panel = new JPanel();
        JButton viewSheltersButton = new JButton("View Shelters");

        viewSheltersButton.addActionListener(e -> {
            List<AnimalShelter> shelters = shelterController.getAllShelters();
            StringBuilder shelterInfo = new StringBuilder();

            for (AnimalShelter shelter : shelters) {
                shelterInfo.append("Shelter: ").append(shelter.getName()).append("\n");
                List<Rating> ratings = ratingController.getRatingsForShelter(shelter.getId());
                shelterInfo.append("Ratings: ").append(ratings.size()).append("\n");

                double avgRating = ratings.stream()
                        .mapToInt(Rating::getValue)
                        .average()
                        .orElse(0.0);

                shelterInfo.append("Average Rating: ").append(avgRating).append("\n\n");
            }

            JOptionPane.showMessageDialog(null, shelterInfo.toString());
        });

        panel.add(viewSheltersButton);
        add(panel);
    }
}
