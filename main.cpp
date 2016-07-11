#include <iostream>
#include "include/api/BamReader.h"
#include "include/api/BamMultiReader.h"

using namespace std;
using namespace BamTools;


void print_header_info (const BamReader & reader){
    SamHeader header = reader.GetHeader();
    cout << "Header " << "[" << header.ToString() << "]" << endl;
}

void print_ref_info (const BamReader & reader){
    cout << "ReferenceCount " << "["<< reader.GetReferenceCount() << "]" << endl;
    RefVector ref_data_vector = reader.GetReferenceData();

    for (int i = 0; i < ref_data_vector.size(); i++ ){
        RefData current_ref_data = ref_data_vector[i];
        cout << i << endl;
        cout << "  RefName " << current_ref_data.RefName << endl;
        cout << "  RefLenght " << current_ref_data.RefLength << endl;
    }
}



int main() {
    string full_filename = "/home/jedi/cchmc/data/bam/small/wgEncodeUwRepliSeqBjG1bAlnRep1.bam";

    BamReader reader;
    if (not reader.Open(full_filename)) {
        cout << "Couldn't open file " << full_filename << endl;
        return 0;
    } else cout << "Open " << reader.GetFilename() << endl;

    print_header_info (reader);
    print_ref_info (reader);





    return 0;
}