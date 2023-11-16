#include "mix.h"

void mix(std::string read_vardas, std::string write_vardas) {
    std::vector<std::string> splited;
    std::string eil;
    //----------------------------------------------------------------------
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    std::ifstream open_f(read_vardas);
    while (open_f) {
        if (!open_f.eof()) {
            std::getline(open_f, eil);
            splited.push_back(eil);
        }
        else break;
    }
    open_f.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo nuskaitymas tesiai i eiluciu vektoriu uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::string outputas = "";
    for (std::string& a : splited) (a.compare(*splited.rbegin()) != 0) ? outputas += a + "\n" : outputas += a;
    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Eiluciu vektoriiaus konvertavimas i viena eilute uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::ofstream out_f(write_vardas);
    out_f << outputas;
    out_f.close();
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Failo irasymas per vien? eilute uztruko: " << diff.count() << " s\n";
    //std::cout<<outputas;
    diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    std::cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";
}
