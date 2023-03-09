import java.sql.Connection;
import java.sql.DriverManager;

public class Main {
    public static void main(String[] args) {
        Connection connection = DriverManager.getConnection("jdbc:mysql:sql7.freesqldatabase.com:3306/sql7604300", "sql7604300", "UfKbvY7Gpw");
    }
}