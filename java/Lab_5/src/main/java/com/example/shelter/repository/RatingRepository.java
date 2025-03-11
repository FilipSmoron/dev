package com.example.shelter.repository;

import com.example.shelter.model.Rating;
import com.example.shelter.model.Shelter;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface RatingRepository extends JpaRepository<Rating, Long> {
    List<Rating> findByShelter(Shelter shelter);
}
