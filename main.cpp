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

void get_alignment_info (BamAlignment al){
    cout
    <<"\n"<< al.Name.c_str()
    <<"\n IsDuplicate:"<<	al.IsDuplicate()
    <<"\n IsFailedQC"<<	 	al.IsFailedQC()
    <<"\n IsMaped:"<< 	  	al.IsMapped()
    <<"\n isFirstMate:"<< 	al.IsFirstMate()
    <<"\n isSecondMate:"<< 	al.IsSecondMate()
    <<"\n IsMateMapped:"<< 	al.IsMateMapped()
    <<"\n IsMateReverseStrand:"<< al.IsMateReverseStrand() // returns true if alignment's mate mapped to reverse strand
    <<"\n IsReverseStrand:"<<	al.IsReverseStrand()
    <<"\n IsPaired:"<<		al.IsPaired()
    <<"\n IsPrimaryAlignment:"<<al.IsPrimaryAlignment()
    <<"\n IsProperPair:"<<	al.IsProperPair()
    <<"\n AligmentFlag:"<<	al.AlignmentFlag
//    <<"\n MateRefId:"<<		references[al.MateRefID].RefName.c_str()
    <<"\n Len:"<<	    	al.Length
    <<"\n InsertSize:"<<	al.InsertSize
    <<"\n MatePosition:["<<al.MatePosition<<"] ";
//    <<"\n Position:["<<references[al.RefID].RefName.c_str()<<":"<<al.Position+1<<"-"<<al.GetEndPosition()<<"] ";
}

void print_alignments_info (BamReader reader){
    BamAlignment current_alignment;
    while (reader.GetNextAlignmentCore(current_alignment)){
        get_alignment_info (current_alignment);
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
    print_alignments_info (reader);

    return 0;
}