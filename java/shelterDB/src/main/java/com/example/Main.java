package com.example;

import com.example.ui.AdminView;
import com.example.ui.UserView;
import com.example.dao.BaseDAO;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        // Inicjalizacja Hibernate
        BaseDAO.initialize();

        // Wybór trybu
        SwingUtilities.invokeLater(() -> {
            String[] options = {"Admin", "User"};
            int choice = JOptionPane.showOptionDialog(
                    null,
                    "Choose mode:",
                    "Shelter Management System",
                    JOptionPane.DEFAULT_OPTION,
                    JOptionPane.INFORMATION_MESSAGE,
                    null,
                    options,
                    options[0]
            );

            if (choice == 0) {
                new AdminView().setVisible(true);
            } else if (choice == 1) {
                new UserView().setVisible(true);
            }
        });
    }
}
