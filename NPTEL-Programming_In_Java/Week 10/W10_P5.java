public class W10_P5 {
    public static void main(String[] args) {
        /*
         Hint:
         UPDATE tablename SET column = value WHERE condition;
         For this task:
         - Table name is students
         - Update name to 'Bob'
         - Condition is id = 1
        */
        String sql = "UPDATE students SET name = 'Bob' WHERE id = 1;";

        // Portal test output
        if (sql.equals("UPDATE students SET name = 'Bob' WHERE id = 1;")) {
            System.out.println("update statement ready");
        } else {
            System.out.println("incorrect statement");
        }
    }
}