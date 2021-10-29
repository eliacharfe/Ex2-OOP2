## Ex2-OOP2
2nd year 2nd semester

תרגיל 2 - OOP2 ex2
תרגול תבניות

אלישר פייג 302278338 (שם מלא: אלישר מאיר משה פייג)
שגיא אביטל 305295826

הסבר כללי:

בתרגיל זה נבנה אפליקצייה מבוססת טרמינל שתשמש למילוי טופס הזמנת חדרים בבית מלון
לחופשה משפחתית.
בבית המלון יש 20 חדרים. 10 חדרים זוגיים (יש רק שתי מיטות בחדר) ו־10 חדרים משפחתיים (יש חמש מיטות בחדר).
 
תיאור התוכנית:

התוכנית מבקשת מהמשתמש הזמנה אחת. המשתמש ממלא שדה אחר שדה ולאחר מכן התוכנית בודקת את תקינות הטופס
ומציגה למילוי חוזר את השדות בעלי השגיאה בצירוף השגיאות המתאימות. לבסוף, כשהשדות תקינים, מציגה התוכנית הודעת תודה 
ואת  המחיר הכולל שיצא ויוצאת.

תיכון (Desing):

התוכנית מנוהל ע"י פונקציית main.

main

BaseField

BaseValidator

BaseValidator <|-- DateValidator 
BaseValidator <|-- IDValidator 
BaseValidator <|-- NoDigitValidator 
BaseValidator <|-- NonNegativeValidator 
BaseValidator <|-- NotGreaterThanValidator 
BaseValidator <|-- RangeValidator 
BaseValidator <|-- RoomValidator 
BaseValidator <|-- SumValidator 

BaseField <|-- Field<T>a
BaseField <|-- Field<string>a
BaseField <|-- Field<uni_t32>a
BaseField <|-- Field<int>a

Form

Consts

Utillities


מבני נתונים:

Field

בBaseValidator:
vector < int > m_answers

פונקציות ווירטואליות ב BaseField:
virtual string getString(const int i) const = 0
virtual BaseValidator* getValidator(const int i) const = 0
virtual int getContent() const = 0

פונקציות ווירטואליות ב BaseValidator:
virtual bool checkValid(int num) const = 0
