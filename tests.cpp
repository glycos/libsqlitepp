#include <iostream>

#include "libsqlite.hpp"

int main()
{
    try
    {
        sqlite::sqlite db(":memory:");  // Open an in-memory database
                                        // Will auto close on destruction
        sqlite::statement_ptr s = db.get_statement();
        s->set_sql("CREATE TABLE test(id INTEGER PRIMARY KEY, text TEXT)");
        s->exec(); //exec calls prepare and step at once.

        // When a shared_ptr like statement_pt is assigned another value, it deletes 
        // its contents. So s = db.get_statement(); Would do almost the same, except
        // it would clear its bindings, which are NOT done now! As we don't have bindings,
        // we don't care right now.
        s->reset();


        // INSERT example without bind.
        s->set_sql("INSERT INTO test(text) VALUES('test')");
        s->exec();
        std::cout << "Inserted into test without binding values." << std::endl;


        // Reset the statement again.
        s->reset();


        std::string special_text = "text with ap'ostrophes and sla/shes in both \\ \
            directions are handled perfectly with bind!";

        s->set_sql("INSERT INTO test(text) VALUES(?)");
        s->prepare();
        s->bind(1, special_text); // sqlite starts counting at 0
        s->step();
        std::cout << "Inserted into test with binding values." << std::endl;
        

        //Another reset. Bear in mind that bindings are NOT cleared.
        s->reset();


        s->set_sql("INSERT into test(text) VALUES(?5)");
        s->prepare();
        s->bind(5, special_text);   // If we specify an integer literal after the
                                    // question mark, we can use that number, which is
                                    // very useful in longer queries.
        s->step();
        std::cout << "Inserted into test with binding values to integer literal." << std::endl;

        s->reset();
        s->prepare(); // You can reuse your sql of the previous query.
        s->bind(5, "other test, reuse text");
        s->step();
        std::cout << "Inserted into test with reuse of sql." << std::endl;


        s->reset(); // We know what this does...


        // SELECT example.
        s->set_sql("SELECT id, text FROM test");
        s->prepare();
        std::cout << "Retrieve values:" << std::endl;
        while(s->step())
        {
            std::cout << s->get_int(0) << " " << s->get_text(1) << std::endl;
        }
    }
    catch(sqlite::exception e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
