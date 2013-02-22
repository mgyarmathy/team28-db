#ifndef _DB_EXCEPTIONS_H_
#define _DB_EXCEPTIONS_H_

class __declspec(dllexport) OutOfBoundsException{};
class __declspec(dllexport) FileNotFoundException{};
class __declspec(dllexport) ColumnAlreadyExistsException{};
class __declspec(dllexport) RowTooLargeException{};
class __declspec(dllexport) ColumnNotFoundException{};
class __declspec(dllexport) TableNotFoundException{};
class __declspec(dllexport) InvalidTypeForOperationException{};
class __declspec(dllexport) IsNullException{};
class __declspec(dllexport) IsInvalidException{};
class __declspec(dllexport) NoMatchingKeysException{};
class __declspec(dllexport) InvalidAttributeNameException{};

#endif
