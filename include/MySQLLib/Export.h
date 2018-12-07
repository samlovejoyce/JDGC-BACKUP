#ifndef EXPORT_H
#define EXPORT_H

#ifdef MYSQLLIB_EXPORT
#define MYSQLLIB_API __declspec(dllexport)
#else
#define MYSQLLIB_API __declspec(dllimport)
#endif // !MYSQLLIB_EXPORT

#endif // !EXPORT_H
