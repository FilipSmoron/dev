package com.example.dao;

import com.example.HibernateUtil;
import com.example.model.Rating;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityTransaction;

import java.util.List;

public class RatingDAO extends BaseDAO {

    // Zmienione save() z użyciem EntityManager
    public void save(Rating rating) {
        EntityManager entityManager = HibernateUtil.getEntityManager();
        EntityTransaction transaction = entityManager.getTransaction();

        try {
            transaction.begin(); // Rozpoczęcie transakcji
            entityManager.merge(rating); // Zapisz lub zaktualizuj obiekt
            transaction.commit(); // Zatwierdzenie transakcji
        } catch (RuntimeException e) {
            if (transaction.isActive()) {
                transaction.rollback(); // W razie błędu, wycofaj transakcję
            }
            throw e;
        }
    }

    // Zmienione getById() z użyciem EntityManager
    public Rating getById(Long id) {
        EntityManager entityManager = HibernateUtil.getEntityManager();
        return entityManager.find(Rating.class, id); // Użycie find() do pobrania obiektu
    }

    // Zmienione getAllForShelter() z użyciem EntityManager
    public List<Rating> getAllForShelter(Long shelterId) {
        EntityManager entityManager = HibernateUtil.getEntityManager();
        return entityManager.createQuery("from Rating where shelter.id = :shelterId", Rating.class)
                .setParameter("shelterId", shelterId)
                .getResultList(); // Użycie getResultList() zamiast list()
    }

    // Zmienione delete() z użyciem EntityManager
    public void delete(Long id) {
        EntityManager entityManager = HibernateUtil.getEntityManager();
        EntityTransaction transaction = entityManager.getTransaction();

        try {
            transaction.begin(); // Rozpoczęcie transakcji
            Rating rating = entityManager.find(Rating.class, id); // Znalezienie obiektu
            if (rating != null) {
                entityManager.remove(rating); // Usunięcie obiektu
            }
            transaction.commit(); // Zatwierdzenie transakcji
        } catch (RuntimeException e) {
            if (transaction.isActive()) {
                transaction.rollback(); // W razie błędu, wycofaj transakcję
            }
            throw e;
        }
    }
}
