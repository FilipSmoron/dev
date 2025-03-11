package com.example.dao;

import com.example.model.Animal;
import org.hibernate.Session;
import org.hibernate.Transaction;

public class AnimalDAO extends BaseDAO {

    public void save(Animal animal) {
        try (Session session = getSession()) { // Poprawione otwarcie sesji
            Transaction tx = session.beginTransaction();
            session.saveOrUpdate(animal);
            tx.commit();
        }
    }

    public Animal getById(Long id) {
        try (Session session = getSession()) { // Poprawione otwarcie sesji
            return session.get(Animal.class, id);
        }
    }
}
