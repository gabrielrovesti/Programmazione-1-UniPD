
//Soluzione by: Gomez E. (Riccardo G. A.)

#include <fstream>
using namespace std;
 
struct vslices {
    int cols, current_len, *data;
    vslices(int* a, int l = 0, int c = 0) {
        data = a;
        current_len = l;
        cols = c;
    }
};
 
struct pattern {
    int length, *data;
    pattern(int* a, int l = 0) {
        data = a;
        length = l;
    }
};
 
void print(ofstream& out, int index, int matches) {
    out << "V fetta " << index << "=" << matches << " match" << endl;
}
 
void print_matches(ofstream& out, int index, vslices& s, pattern& p) {
    int len = s.current_len - (p.length - 1);
    int matches = 0;
 
    for (int i = 0; i < len; i++) {
        bool ok = true;
 
        for (int j = 0; j < p.length && ok; j++) {
            ok = p.data[j] == s.data[index + ((i+j) * s.cols)];
        }
 
        if (ok) {
            matches++;
            i = i + p.length - 1;
        }
    }
 
    print(out, index, matches);
}
 
int main() {
    int X[400];
    int P[50];
    int lim1, lim2, lim3, n_el, dimP;
 
    for (int i = 0; i < 400; i++) {
        X[i] = -1;
    }
 
    ifstream input_file("input");
    input_file >> lim1 >> lim2 >> lim3 >> n_el;
 
    for (int i = 0; i < n_el; i++) {
        input_file >> X[i];
    }
 
    input_file >> dimP;
 
    for (int i = 0; i < dimP; i++) {
        input_file >> P[i];
    }
    
    input_file.close();
    
    int n_slices = n_el;
    if (n_slices > lim3) n_slices = lim3;
    int vslice_max_size = lim1 * lim2;
    int vslice_size = n_el / lim3;
    int full_slices = n_el % lim3;
    if (full_slices > 0) vslice_size++;
    if (vslice_size > vslice_max_size) {
        vslice_size = vslice_max_size;
        full_slices = lim3;
    }
 
    vslices s(X, vslice_size, lim3);
    pattern p(P, dimP);
    ofstream output_file("output");
 
    for (int i = 0; i < n_slices; i++) {
        if (i == full_slices) s.current_len = vslice_size - 1;
        print_matches(output_file, i, s, p);
    }
 
    output_file.close();
}
