// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.ExprInspection -verify %s

template <typename T> void clang_analyzer_dump(T);
template <typename T> void clang_analyzer_value(T);
void clang_analyzer_warnIfReached();

struct Node { int* ptr; };

void copy_on_stack(Node* n1) {
  Node tmp = *n1;
  Node* n2 = &tmp;
  clang_analyzer_dump(n1); // expected-warning-re {{&SymRegion{reg_${{[0-9]+}}<Node * n1>}}}
  clang_analyzer_dump(n2); // expected-warning {{&tmp}}

  clang_analyzer_dump(n1->ptr); // expected-warning-re {{&SymRegion{reg_${{[0-9]+}}<int * Element{SymRegion{reg_${{[0-9]+}}<Node * n1>},0 S64b,struct Node}.ptr>}}}
  clang_analyzer_dump(n2->ptr); // expected-warning-re {{&SymRegion{reg_${{[0-9]+}}<int * Element{SymRegion{reg_${{[0-9]+}}<Node * n1>},0 S64b,struct Node}.ptr>}}}

  if (n1->ptr != n2->ptr)
    clang_analyzer_warnIfReached(); // unreachable
  (void)(n1->ptr);
  (void)(n2->ptr);
}

void copy_on_heap(Node* n1) {
  Node* n2 = new Node(*n1);

  clang_analyzer_dump(n1); // expected-warning-re {{&SymRegion{reg_${{[0-9]+}}<Node * n1>}}}
  clang_analyzer_dump(n2); // expected-warning-re {{&HeapSymRegion{conj_${{[0-9]+}}{Node *, LC{{[0-9]+}}, S{{[0-9]+}}, #{{[0-9]+}}}}}}

  clang_analyzer_dump(n1->ptr); // expected-warning-re {{&SymRegion{reg_${{[0-9]+}}<int * Element{SymRegion{reg_${{[0-9]+}}<Node * n1>},0 S64b,struct Node}.ptr>}}}
  clang_analyzer_dump(n2->ptr); // expected-warning-re {{&SymRegion{reg_${{[0-9]+}}<int * Element{SymRegion{reg_${{[0-9]+}}<Node * n1>},0 S64b,struct Node}.ptr>}}}

  if (n1->ptr != n2->ptr)
    clang_analyzer_warnIfReached(); // unreachable
  (void)(n1->ptr);
  (void)(n2->ptr);
}

struct List {
  List* next;
  int value;
  int padding;
};

void deadCode(List orig) {
  List c = orig;
  clang_analyzer_dump(c.value);
  // expected-warning-re@-1 {{reg_${{[0-9]+}}<int orig.value>}}
  if (c.value == 42)
    return;
  clang_analyzer_value(c.value);
  // expected-warning@-1 {{32s:{ [-2147483648, 2147483647] }}}
  // The symbol was garbage collected too early, hence we lose the constraints.
  if (c.value != 42)
    return;

  // Dead code should be unreachable
  clang_analyzer_warnIfReached(); // expected-warning {{REACHABLE}}
}
