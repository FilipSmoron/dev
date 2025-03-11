package com.example.dao;

import com.example.model.AnimalShelter;
import org.hibernate.Session;
import org.hibernate.Transaction;
import com.example.HibernateUtil;
import java.util.List;
import java.util.ArrayList;

public class AnimalShelterDAO {

    public void save(AnimalShelter shelter) {
        Transaction transaction = null;
        try (Session session = HibernateUtil.getSessionFactory().openSession()) {
            transaction = session.beginTransaction();
            session.saveOrUpdate(shelter);
            transaction.commit();
        } catch (Exception e) {
            if (transaction != null) {
                transaction.rollback();
            }
            e.printStackTrace();
        }
    }

    public AnimalShelter getById(Long id) {
        try (Session session = HibernateUtil.getSessionFactory().openSession()) {
            return session.get(AnimalShelter.class, id);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public List<AnimalShelter> getAll() {
        try (Session session = HibernateUtil.getSessionFactory().openSession()) {
            return session.createQuery("FROM com.example.model.AnimalShelter", AnimalShelter.class).list();
        } catch (Exception e) {
            e.printStackTrace();
            return new ArrayList<>();
        }
    }

    public void delete(Long id) {
        Transaction transaction = null;
        try (Session session = HibernateUtil.getSessionFactory().openSession()) {
            transaction = session.beginTransaction();
            AnimalShelter shelter = session.get(AnimalShelter.class, id);
            if (shelter != null) {
                session.remove(shelter);
            }
            transaction.commit();
        } catch (Exception e) {
            if (transaction != null) {
                transaction.rollback();
            }
            e.printStackTrace();
        }
    }

    // Dodatkowe metody - opcjonalnie
    public List<AnimalShelter> findByLocation(String location) {
        try (Session session = HibernateUtil.getSessionFactory().openSession()) {
            return session.createQuery("FROM com.example.model.AnimalShelter", AnimalShelter.class)
                    .setParameter("location", "%" + location + "%")
                    .list();
        } catch (Exception e) {
            e.printStackTrace();
            return new ArrayList<>();
        }
    }

    public long countShelters() {
        try (Session session = HibernateUtil.getSessionFactory().openSession()) {
            return session.createQuery("SELECT COUNT(s) FROM com.example.model.AnimalShelter s", Long.class).uniqueResult();
        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
    }
}