public class W10_P3 {
    public static void main(String[] args) {
        /*
         Hint:
         SQL insert format: INSERT INTO tablename (columns) VALUES (values);
         For this task:
         - Table name is students
         - Columns are id and name
         - Values are 1 and 'Alice'
        */
        String sql = "INSERT INTO students (id, name) VALUES (1, 'Alice');";

        // Portal test output
        if (sql.equals("INSERT INTO students (id, name) VALUES (1, 'Alice');")) {
            System.out.println("insert statement ready");
        } else {
            System.out.println("incorrect statement");
        }
    }
}