import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LoginView extends JFrame {
    private final ShelterManager shelterManager;

    public LoginView(ShelterManager shelterManager) {
        this.shelterManager = shelterManager; // Przypisanie shelterManager
        setTitle("Login");
        setSize(300, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        JLabel label = new JLabel("Choose Role:");
        JButton userButton = new JButton("User");
        JButton adminButton = new JButton("Admin");

        userButton.addActionListener(e -> new UserView(shelterManager).setVisible(true)); // Przekazanie shelterManager
        adminButton.addActionListener(e -> new AdminView(shelterManager).setVisible(true)); // Przekazanie shelterManager

        panel.add(label);
        panel.add(userButton);
        panel.add(adminButton);
        add(panel);
    }
}
