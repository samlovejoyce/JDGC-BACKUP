#ifndef TERRAINELEVATION_EXPORT_H
#define TERRAINELEVATION_EXPORT_H


#ifdef TERRAINELEVATIONDB_DLL
#define TERRAINELEVATIONDB_API __declspec(dllexport)
#else
#define  TERRAINELEVATIONDB_API __declspec(dllimport)
#endif


#endif // TERRAINELEVATION_EXPORT_H