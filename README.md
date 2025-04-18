# **2D Parity & Error Detection**

## **Περιγραφή**
Πρόγραμμα σε **C++** που υλοποιεί ελέγχους ισοτιμίας (άρτιας) και δισδιάστατης ανάλυσης για ανίχνευση σφαλμάτων. Συγκεκριμένα, περιλαμβάνει: προσθήκη parity bit σε μήνυμα 14 bits, έλεγχο για 0/1/2 σφάλματα (τα ζυγά δεν εντοπίζονται), δημιουργία 4x7 πίνακα (28 bits) με parity bits γραμμών/στηλών, και ανάλυση σφαλμάτων σε 2D δομή).

---

### 🚀 **Project Overview**
Αυτό το project εστιάζει στην ανίχνευση σφαλμάτων μέσω:
- **Προσθήκης Parity Bit** σε μήνυμα 14 bits.
- **Δημιουργίας 4x7 πίνακα (28 bits)** με parity bits γραμμών/στηλών.
- **Πειραματικής ανάλυσης** για σφάλματα σε 2D δομή (π.χ., 2 σφάλματα στην ίδια γραμμή/στήλη που "ξεγελούν" την ισοτιμία).

---

### 🔍 **Key Features**
- **Άρτια Ισοτιμία**: Υπολογισμός/προσθήκη parity bit για εξασφάλιση άρτιου αριθμού '1'.
- **Δισδιάστατος Έλεγχος**: Ανίχνευση σφαλμάτων με ανάλυση γραμμών **και** στηλών.
- **Σενάρια Σφαλμάτων**:
  - **0/1 σφάλμα**: Ανίχνευση μέσω ισοτιμίας.
  - **2 σφάλματα**: Αποτυχία ανίχνευσης αν βρίσκονται στην ίδια γραμμή/στήλη.

---

### 🛠️ **Technical Highlights**
- **Δομές Δεδομένων**: Πίνακες, διαχείριση bits, και επαλήθευση ισοτιμίας.
- **Συναρτήσεις Σφάλματος**: Προσομοίωση αλλαγών bits (0 ↔ 1) σε συγκεκριμένες θέσεις.
- **Αποτελεσματικότητα**: Διερεύνηση **ορίων ισοτιμίας** και ανάγκης δισδιάστατης προστασίας.

---

### 📂 **Code Structure**
- **main.cpp**: Διαχείριση εισόδου/εξόδου, κλήση συναρτήσεων.
- **Parity Utilities**: Συναρτήσεις για υπολογισμό parity, δημιουργία πίνακα, και έλεγχο σφαλμάτων.

---

**🏷️ Tags**: `C++`, `Parity Check`, `Error Detection`, `2D Matrix`, `Data Integrity`
**🌟 Concept**: *"Ένα εκπαιδευτικό εργαλείο για την κατανόηση της σημασίας της δισδιάστατης επαλήθευσης στην ανίχνευση σφαλμάτων και των ορίων της απλής ισοτιμίας."*
