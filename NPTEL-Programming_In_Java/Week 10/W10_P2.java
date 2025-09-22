public class W10_P2 {
    public static void main(String[] args) {
        /*
         Hint:
         JDBC connection string for SQLite starts with "jdbc:sqlite:"
         The database file is "test.db"
        */
        String url = "jdbc:sqlite:test.db";

        // Portal test output
        if (url.equals("jdbc:sqlite:test.db")) {
            System.out.println("connection string ready");
        } else {
            System.out.println("incorrect connection string");
        }
    }
}