import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        ShelterManager shelterManager = new ShelterManager(); // Inicjalizacja obiektu ShelterManager
        SwingUtilities.invokeLater(() -> {
            LoginView loginView = new LoginView(shelterManager); // Przekazanie shelterManager do LoginView
            loginView.setVisible(true);
        });
    }
}
