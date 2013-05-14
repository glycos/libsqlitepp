#include <iostream>

#include "libsqlite.hpp"

int main()
{
    sqlite::sqlite db(":memory:");  // Open an in-memory database
                                    // Will auto close on destruction
    std::shared_ptr<sqlite::statement> s = db.get_statement();
    s->set_sql("CREATE TABLE test(id INTEGER PRIMARY KEY, text TEXT)");
    s->exec();

    // When shared_ptr is assigned another value, it deletes its contents.
    // So s = db.get_statement(); Would do almost the same, except it would
    // clear its bindings, which are NOT done now! As we don't have bindings,
    // we don't care right now.
    s->reset();

    // INSERT example without bind.
    s->set_sql("INSERT INTO test(text) VALUES('test')");
    s->exec();

    std::cout << "Inserted into test without binding values." << std::endl;

    // Reset the statement again.
    s->reset();

    // SELECT example.
    s->set_sql("SELECT id, text FROM test");
    s->prepare();
    std::cout << "Retrieve values:" << std::endl;
    while(s->step())
    {
        std::cout << s->get_int(0) << " " << s->get_text(1) << std::endl;
    }

    return 0;
}
