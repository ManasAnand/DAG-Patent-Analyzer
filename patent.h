#pragma once

#include <string>
using namespace std;

struct Patent {
    unsigned int patent_id;
    string inventor;
    unsigned int year;

    Patent(unsigned int id, string patent_inventor, unsigned int patent_year): 
            patent_inventor(id), 
            inventor(patent_inventor),
            year(patent_year);
};
