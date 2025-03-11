package com.example.controller;

import com.example.dao.AnimalShelterDAO;
import com.example.model.AnimalShelter;

import java.util.List;

public class ShelterController {
    private final AnimalShelterDAO shelterDAO = new AnimalShelterDAO();

    // Dodanie schroniska
    public void addShelter(String name, int maxCapacity) {
        AnimalShelter shelter = new AnimalShelter();
        shelter.setName(name);
        shelter.setMaxCapacity(maxCapacity);
        shelterDAO.save(shelter); // Użycie DAO do zapisania schroniska
    }

    // Pobranie wszystkich schronisk
    public List<AnimalShelter> getAllShelters() {
        return shelterDAO.getAll(); // Użycie DAO do pobrania wszystkich schronisk
    }

    // Usunięcie schroniska po ID
    public void deleteShelter(Long id) {
        shelterDAO.delete(id); // Użycie DAO do usunięcia schroniska
    }
}
