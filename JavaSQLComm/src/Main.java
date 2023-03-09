import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Main {

        public static void main (String[]args){
            try {
                Connection connection = DriverManager.getConnection("jdbc:mysql:sql7.freesqldatabase.com:3306/sql7604300", "sql7604300", "UfKbvY7Gpw");
                Statement statement = connection.createStatement();
                statement.executeUpdate("INSERT INTO Coordinates VALUES (100.50, 234.567);");
                ResultSet resultSet = statement.executeQuery("SELECT * FROM Coordinates");
                while (resultSet.next()) {
                    System.out.println(resultSet.getString("coordinateX, coordinateY"));
                }
            }catch (Exception e){
            e.printStackTrace();
        }
    }
}