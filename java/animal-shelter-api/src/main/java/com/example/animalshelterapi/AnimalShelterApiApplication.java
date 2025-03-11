package com.example.animalshelterapi;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;

@SpringBootApplication
@EnableJpaRepositories(basePackages = "com.example.animalshelterapi")
public class AnimalShelterApiApplication {

    public static void main(String[] args) {
        SpringApplication.run(AnimalShelterApiApplication.class, args);
    }
}
