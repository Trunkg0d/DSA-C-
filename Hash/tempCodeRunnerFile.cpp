CompanyNode** HashTable = CreateHashTable(vect);
    CompanyNode* c = Search(HashTable, "CONG TY TNHH BEE VIET NAM");
    cout << c->company.name << endl;
    CompanyNode* t = Search(HashTable, "CONG TY TNHH DICH VU VA PHAT TRIEN THUONG MAI KIM LONG");
    cout << t->company.name << endl;