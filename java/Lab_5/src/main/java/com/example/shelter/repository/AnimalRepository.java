package com.example.shelter.repository;

import com.example.shelter.model.Animal;
import com.example.shelter.model.Shelter;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface AnimalRepository extends JpaRepository<Animal, Long> {
    List<Animal> findByShelter(Shelter shelter);
    List<Animal> findBySpecies(String species);
    List<Animal> findByAgeBetween(int minAge, int maxAge);
}
