public class W10_P4 {
    public static void main(String[] args) {
        /*
         Hint:
         To fetch all columns from a table:
         SELECT * FROM tablename;
         For this task:
         - Table name is students
        */
        String sql = "SELECT * FROM students;";

        if (sql.equals("SELECT * FROM students;")) {
            System.out.println("select statement ready");
        } else {
            System.out.println("incorrect statement");
        }
    }
}