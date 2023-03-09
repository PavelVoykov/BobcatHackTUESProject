import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Main {
        public static void Insert(double coordinateX, double coordinateY){

            try{
                Connection connection = DriverManager.getConnection("jdbc:mysql://sql7.freesqldatabase.com:3306/sql7604300", "sql7604300", "UfKbvY7Gpw");
                Statement statement = connection.createStatement();
                statement.executeUpdate("INSERT INTO Coordinates (coordinateX, coordinateY) VALUES ("+coordinateX+"," +coordinateY+");");
            }catch(Exception e){
                e.printStackTrace();
            }

        }
        public static void Select(){

            try{
                Connection connection = DriverManager.getConnection("jdbc:mysql://sql7.freesqldatabase.com:3306/sql7604300", "sql7604300", "UfKbvY7Gpw");
                Statement statement = connection.createStatement();
                ResultSet resultSet = statement.executeQuery("SELECT * FROM Coordinates");
                while (resultSet.next()) {
                    System.out.println(resultSet.getString("id"));
                    System.out.println(resultSet.getString("coordinateX"));
                    System.out.println(resultSet.getString("coordinateY"));
                }
            }catch(Exception e){
                e.printStackTrace();
            }

        }
        public static void main (String[]args){
            Insert(154.5937219, 461.09745876);
            Select();
        }
}