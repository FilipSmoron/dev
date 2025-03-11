package com.example.animalshelterapi;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ShelterRepository extends JpaRepository<AnimalShelter, Long> {
    void deleteById(String name);
    // dodatkowe zapytania, jeśli są potrzebne
}
