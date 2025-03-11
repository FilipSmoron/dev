package com.example.controller;

import com.example.dao.RatingDAO;
import com.example.dao.AnimalShelterDAO;
import com.example.model.Rating;
import com.example.model.Rating;
import com.example.model.AnimalShelter;

import java.time.LocalDate;
import java.util.List;

public class RatingController {
    private final RatingDAO ratingDAO = new RatingDAO();
    private final AnimalShelterDAO shelterDAO = new AnimalShelterDAO();

    public void addRating(int value, String comment, Long shelterId) {
        AnimalShelter shelter = shelterDAO.getById(shelterId);
        if (shelter == null) {
            throw new IllegalArgumentException("Shelter not found");
        }

        Rating rating = new Rating();
        rating.setValue(value);
        rating.setComment(comment);
        rating.setDate(LocalDate.now());
        rating.setShelter(shelter);

        ratingDAO.save(rating);
    }

    public List<Rating> getRatingsForShelter(Long shelterId) {
        return ratingDAO.getAllForShelter(shelterId);
    }
}
