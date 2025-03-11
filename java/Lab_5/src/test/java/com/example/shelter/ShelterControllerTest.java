package com.example.shelter;

import com.example.shelter.controller.ShelterController;
import com.example.shelter.model.Animal;
import com.example.shelter.model.Rating;
import com.example.shelter.model.Shelter;
import com.example.shelter.service.ShelterService;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.eq;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

class ShelterControllerTest {

    private MockMvc mockMvc;
    private ShelterService shelterService;
    private ObjectMapper objectMapper;

    @BeforeEach
    void setUp() {
        shelterService = Mockito.mock(ShelterService.class);
        ShelterController shelterController = new ShelterController(shelterService);
        mockMvc = MockMvcBuilders.standaloneSetup(shelterController).build();
        objectMapper = new ObjectMapper();
    }

    @Test
    void shouldAddAnimal() throws Exception {
        Animal animal = new Animal();
        animal.setName("Rex");
        animal.setSpecies("Dog");
        animal.setAge(3);

        Mockito.when(shelterService.addAnimal(any(Animal.class))).thenReturn(animal);

        mockMvc.perform(post("/api/animal")
                        .contentType(MediaType.APPLICATION_JSON)
                        .content(objectMapper.writeValueAsString(animal)))
                .andExpect(status().isCreated())
                .andExpect(jsonPath("$.name").value("Rex"))
                .andExpect(jsonPath("$.species").value("Dog"))
                .andExpect(jsonPath("$.age").value(3));

        Mockito.verify(shelterService).addAnimal(any(Animal.class));
    }

    @Test
    void shouldDeleteAnimal() throws Exception {
        Mockito.when(shelterService.deleteAnimal(1L)).thenReturn(true);

        mockMvc.perform(delete("/api/animal/1"))
                .andExpect(status().isNoContent());

        Mockito.verify(shelterService).deleteAnimal(1L);
    }

    @Test
    void shouldGetAnimalById() throws Exception {
        Animal animal = new Animal();
        animal.setId(1L);
        animal.setName("Rex");
        animal.setSpecies("Dog");
        animal.setAge(3);

        Mockito.when(shelterService.getAnimalById(1L)).thenReturn(animal);

        mockMvc.perform(get("/api/animal/1"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.name").value("Rex"))
                .andExpect(jsonPath("$.species").value("Dog"))
                .andExpect(jsonPath("$.age").value(3));

        Mockito.verify(shelterService).getAnimalById(1L);
    }

    @Test
    void shouldExportSheltersToCsv() throws Exception {
        String csvContent = "Id;Name;Location;Capacity\n1;Happy Paws;New York;50\n";

        Mockito.when(shelterService.generateSheltersCsv()).thenReturn(csvContent);

        mockMvc.perform(get("/api/animalshelter/csv"))
                .andExpect(status().isOk())
                .andExpect(content().string(csvContent));

        Mockito.verify(shelterService).generateSheltersCsv();
    }

    @Test
    void shouldGetAllShelters() throws Exception {
        Shelter shelter = new Shelter();
        shelter.setId(1L);
        shelter.setName("Happy Paws");
        shelter.setLocation("New York");
        shelter.setCapacity(50);

        Mockito.when(shelterService.getAllShelters()).thenReturn(Collections.singletonList(shelter));

        mockMvc.perform(get("/api/sheltermanager"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$[0].name").value("Happy Paws"))
                .andExpect(jsonPath("$[0].location").value("New York"))
                .andExpect(jsonPath("$[0].capacity").value(50));

        Mockito.verify(shelterService).getAllShelters();
    }

    @Test
    void shouldAddShelter() throws Exception {
        Shelter shelter = new Shelter();
        shelter.setName("New Shelter");
        shelter.setLocation("Chicago");
        shelter.setCapacity(30);

        Mockito.when(shelterService.addShelter(any(Shelter.class))).thenReturn(shelter);

        mockMvc.perform(post("/api/animalshelter")
                        .contentType(MediaType.APPLICATION_JSON)
                        .content(objectMapper.writeValueAsString(shelter)))
                .andExpect(status().isCreated())
                .andExpect(jsonPath("$.name").value("New Shelter"))
                .andExpect(jsonPath("$.location").value("Chicago"))
                .andExpect(jsonPath("$.capacity").value(30));

        Mockito.verify(shelterService).addShelter(any(Shelter.class));
    }

    @Test
    void shouldDeleteShelter() throws Exception {
        Mockito.when(shelterService.deleteShelter(1L)).thenReturn(true);

        mockMvc.perform(delete("/api/animalshelter/1"))
                .andExpect(status().isNoContent());

        Mockito.verify(shelterService).deleteShelter(1L);
    }

    @Test
    void shouldGetAnimalsInShelter() throws Exception {
        Animal animal1 = new Animal();
        animal1.setId(1L);
        animal1.setName("Rex");
        animal1.setSpecies("Dog");

        Mockito.when(shelterService.getAnimalsInShelter(1L))
                .thenReturn(Collections.singletonList(animal1));

        mockMvc.perform(get("/api/animalshelter/1/animal"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$[0].name").value("Rex"))
                .andExpect(jsonPath("$[0].species").value("Dog"));

        Mockito.verify(shelterService).getAnimalsInShelter(1L);
    }

    @Test
    void shouldCalculateShelterFillPercentage() throws Exception {
        Mockito.when(shelterService.calculateShelterFillPercentage(1L)).thenReturn(50.0);

        mockMvc.perform(get("/api/animalshelter/1/fill"))
                .andExpect(status().isOk())
                .andExpect(content().string("50.0"));

        Mockito.verify(shelterService).calculateShelterFillPercentage(1L);
    }

    @Test
    void shouldAddShelterRating() throws Exception {
        Rating rating = new Rating();
        rating.setRating(4);

        Mockito.when(shelterService.addShelterRating(1L, 4)).thenReturn(rating);

        mockMvc.perform(post("/api/rating")
                .param("shelterId", "1")
                .param("rating", "4"))
                .andExpect(status().isCreated())
                .andExpect(jsonPath("$.rating").value(4));

        Mockito.verify(shelterService).addShelterRating(1L, 4);
    }

    @Test
    void shouldReturnEmptyAnimalListForShelter() throws Exception {
        Mockito.when(shelterService.getAnimalsInShelter(1L)).thenReturn(Collections.emptyList());

        mockMvc.perform(get("/api/animalshelter/1/animal"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$").isEmpty());

        Mockito.verify(shelterService).getAnimalsInShelter(1L);
    }
}