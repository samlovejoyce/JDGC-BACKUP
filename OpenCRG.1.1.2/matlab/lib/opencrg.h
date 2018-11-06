//
// MATLAB Compiler: 6.6 (R2018a)
// Date: Fri Jul 27 10:56:20 2018
// Arguments:
// "-B""macro_default""-W""cpplib:opencrg""-T""link:lib""copy_ax2fig.m""crg_appe
// nd.m""crg_b2z.m""crg_check.m""crg_check_data.m""crg_check_head.m""crg_check_m
// ods.m""crg_check_opts.m""crg_check_single.m""crg_check_uv_descript.m""crg_cut
// _iuiv.m""crg_eval_u2crv.m""crg_eval_u2phi.m""crg_eval_uv2iuiv.m""crg_eval_uv2
// xy.m""crg_eval_uv2z.m""crg_eval_xy2uv.m""crg_eval_xy2z.m""crg_ext_banking.m""
// crg_ext_slope.m""crg_figure.m""crg_filter.m""crg_flip.m""crg_gen_csb2crg0.m""
// crg_gen_ppxy2phi.m""crg_gen_pxy2ppxy.m""crg_isequal.m""crg_limiter.m""crg_map
// _uv2uv.m""crg_map_xy2xy.m""crg_mods.m""crg_peakfinder.m""crg_perform2surface.
// m""crg_plot_elgrid_cross_sect.m""crg_plot_elgrid_limits.m""crg_plot_elgrid_lo
// ng_sect.m""crg_plot_elgrid_uvz_map.m""crg_plot_elgrid_xyz_map.m""crg_plot_ref
// line_curvature.m""crg_plot_refline_elevation.m""crg_plot_refline_heading.m""c
// rg_plot_refline_slope_bank.m""crg_plot_refline_xy_map_and_curv.m""crg_plot_re
// fline_xy_overview_map.m""crg_plot_refline_xyz_map.m""crg_plot_refpnt_distance
// s.m""crg_plot_road_uv2uvz_map.m""crg_plot_road_uv2xyz_map.m""crg_plot_road_uv
// z_map.m""crg_plot_road_xyz_map.m""crg_read.m""crg_rerender.m""crg_s2z.m""crg_
// separate_sb.m""crg_show.m""crg_show_elgrid_cuts_and_limits.m""crg_show_elgrid
// _surface.m""crg_show_info.m""crg_show_isequal.m""crg_show_peaks.m""crg_show_r
// efline_elevation.m""crg_show_refline_map.m""crg_show_refpnts_and_refline.m""c
// rg_show_road_surface.m""crg_show_road_uv2surface.m""crg_single.m""crg_surf.m"
// "crg_wgs84_crg2html.m""crg_wgs84_dist.m""crg_wgs84_invdist.m""crg_wgs84_seten
// d.m""crg_wgs84_wgs2url.m""crg_wgs84_wgsxy2wgs.m""crg_wgs84_xy2wgs.m""crg_wrap
// .m""crg_write.m""ipl_read.m""ipl_write.m""map_wgs2html.m""sdf_add.m""sdf_cut.
// m""smooth_firfilt.m""str_num2strn.m"
//

#ifndef __opencrg_h
#define __opencrg_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_opencrg_C_API 
#define LIB_opencrg_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_opencrg_C_API 
bool MW_CALL_CONV opencrgInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV opencrgInitialize(void);

extern LIB_opencrg_C_API 
void MW_CALL_CONV opencrgTerminate(void);

extern LIB_opencrg_C_API 
void MW_CALL_CONV opencrgPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCopy_ax2fig(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_append(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_b2z(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_data(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_head(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_mods(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_opts(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_single(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_uv_descript(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_cut_iuiv(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_u2crv(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_u2phi(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_uv2iuiv(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_uv2xy(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_uv2z(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_xy2uv(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_xy2z(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_ext_banking(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                     *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_ext_slope(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_figure(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_filter(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_flip(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_gen_csb2crg0(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_gen_ppxy2phi(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_gen_pxy2ppxy(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_isequal(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_limiter(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_map_uv2uv(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_map_xy2xy(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_mods(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_peakfinder(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_perform2surface(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                         *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_cross_sect(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_limits(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                            *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_long_sect(int nlhs, mxArray *plhs[], int nrhs, 
                                               mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_uvz_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                             *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_xyz_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                             *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_curvature(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_elevation(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_heading(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_slope_bank(int nlhs, mxArray *plhs[], int nrhs, 
                                                 mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_xy_map_and_curv(int nlhs, mxArray *plhs[], int 
                                                      nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_xy_overview_map(int nlhs, mxArray *plhs[], int 
                                                      nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_xyz_map(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refpnt_distances(int nlhs, mxArray *plhs[], int nrhs, 
                                               mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_road_uv2uvz_map(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_road_uv2xyz_map(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_road_uvz_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_road_xyz_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_read(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_rerender(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_s2z(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_separate_sb(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                     *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_elgrid_cuts_and_limits(int nlhs, mxArray *plhs[], int nrhs, 
                                                     mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_elgrid_surface(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                             *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_info(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_isequal(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_peaks(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_refline_elevation(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_refline_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                          *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_refpnts_and_refline(int nlhs, mxArray *plhs[], int nrhs, 
                                                  mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_road_surface(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_road_uv2surface(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_single(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_surf(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_crg2html(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                        *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_dist(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_invdist(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                       *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_setend(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_wgs2url(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                       *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_wgsxy2wgs(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                         *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_xy2wgs(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wrap(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_write(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxIpl_read(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxIpl_write(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxMap_wgs2html(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxSdf_add(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxSdf_cut(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxSmooth_firfilt(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_opencrg_C_API 
bool MW_CALL_CONV mlxStr_num2strn(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_opencrg
#define PUBLIC_opencrg_CPP_API __declspec(dllexport)
#else
#define PUBLIC_opencrg_CPP_API __declspec(dllimport)
#endif

#define LIB_opencrg_CPP_API PUBLIC_opencrg_CPP_API

#else

#if !defined(LIB_opencrg_CPP_API)
#if defined(LIB_opencrg_C_API)
#define LIB_opencrg_CPP_API LIB_opencrg_C_API
#else
#define LIB_opencrg_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_opencrg_CPP_API void MW_CALL_CONV copy_ax2fig();

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_append(int nargout, mwArray& data, mwArray& roff2, const mwArray& data1, const mwArray& data2);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_b2z(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& b);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_check(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_check_data(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_check_head(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_check_mods(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_check_opts(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_check_single(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_check_uv_descript(int nargout, mwArray& v, const mwArray& uv_descript, const mwArray& posmode);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_cut_iuiv(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_eval_u2crv(int nargout, mwArray& crv, mwArray& data, const mwArray& data_in1, const mwArray& pu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_eval_u2phi(int nargout, mwArray& phi, mwArray& data, const mwArray& data_in1, const mwArray& pu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_eval_uv2iuiv(int nargout, mwArray& iu, mwArray& iv, const mwArray& data, const mwArray& u, const mwArray& v);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_eval_uv2xy(int nargout, mwArray& pxy, mwArray& data, const mwArray& data_in1, const mwArray& puv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_eval_uv2z(int nargout, mwArray& pz, mwArray& data, const mwArray& data_in1, const mwArray& puv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_eval_xy2uv(int nargout, mwArray& puv, mwArray& data, const mwArray& data_in1, const mwArray& pxy);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_eval_xy2z(int nargout, mwArray& pz, mwArray& data, const mwArray& data_in1, const mwArray& pxy);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_ext_banking(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& pp);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_ext_slope(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& p);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_figure(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_filter(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv, const mwArray& fm, const mwArray& mask, const mwArray& wopt);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_flip(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_gen_csb2crg0(int nargout, mwArray& data, const mwArray& inc, const mwArray& u, const mwArray& v, const mwArray& c, const mwArray& s, const mwArray& b);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_gen_ppxy2phi(int nargout, mwArray& data, mwArray& err, const mwArray& ppxy, const mwArray& uinc, const mwArray& opts);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_gen_pxy2ppxy(int nargout, mwArray& ppxy, const mwArray& pxy, const mwArray& opts);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_isequal(int nargout, mwArray& ident, mwArray& dd, const mwArray& bcrg, const mwArray& acrg);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_limiter(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& mmlim, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_map_uv2uv(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& crg_uv, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_map_xy2xy(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& crg_xy, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_mods(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_peakfinder(int nargout, mwArray& pindex, mwArray& pij, const mwArray& data, const mwArray& iu, const mwArray& iv, const mwArray& th, const mwArray& ra);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_perform2surface(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& uv_surf, const mwArray& oper);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_elgrid_cross_sect(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_elgrid_limits(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_elgrid_long_sect(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_elgrid_uvz_map(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_elgrid_xyz_map(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_refline_curvature(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_refline_elevation(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_refline_heading(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_refline_slope_bank(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_refline_xy_map_and_curv(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_refline_xy_overview_map(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_refline_xyz_map(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_refpnt_distances(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& pxy);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_road_uv2uvz_map(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& u, const mwArray& v);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_road_uv2xyz_map(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& u, const mwArray& v);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_road_uvz_map(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_plot_road_xyz_map(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_read(int nargout, mwArray& data, const mwArray& file);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_rerender(int nargout, mwArray& data, const mwArray& crg, const mwArray& inc, const mwArray& v);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_s2z(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& rz);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_separate_sb(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& swlen, const mwArray& bwlen);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_elgrid_cuts_and_limits(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_elgrid_surface(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_info(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_isequal(const mwArray& dd, const mwArray& out);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_peaks(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& pindex, const mwArray& su, const mwArray& sv, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_refline_elevation(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_refline_map(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_refpnts_and_refline(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& pxy);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_road_surface(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& iu, const mwArray& iv);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_show_road_uv2surface(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& u, const mwArray& v);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_single(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_surf(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& x, const mwArray& y, const mwArray& z);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_wgs84_crg2html(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& file, const mwArray& opts);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_wgs84_dist(int nargout, mwArray& dist, mwArray& dbeg, mwArray& dend, const mwArray& wgs1, const mwArray& wgs2);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_wgs84_invdist(int nargout, mwArray& wgs2, mwArray& dend, const mwArray& wgs1, const mwArray& dbeg, const mwArray& dist);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_wgs84_setend(int nargout, mwArray& data, const mwArray& data_in1, const mwArray& dref);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_wgs84_wgs2url(int nargout, mwArray& url, const mwArray& wgs, const mwArray& opts);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_wgs84_wgsxy2wgs(int nargout, mwArray& wgs, const mwArray& wgs1, const mwArray& wgs2, const mwArray& pxy1, const mwArray& pxy2, const mwArray& pxy, const mwArray& eps, const mwArray& tol);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_wgs84_xy2wgs(int nargout, mwArray& wgs, mwArray& data, const mwArray& data_in1, const mwArray& pxy);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_wrap(int nargout, mwArray& data, const mwArray& data_in1);

extern LIB_opencrg_CPP_API void MW_CALL_CONV crg_write(int nargout, mwArray& ier, const mwArray& data, const mwArray& file);

extern LIB_opencrg_CPP_API void MW_CALL_CONV ipl_read(int nargout, mwArray& data, const mwArray& filename, const mwArray& opts);

extern LIB_opencrg_CPP_API void MW_CALL_CONV ipl_write(int nargout, mwArray& ier, const mwArray& data, const mwArray& filename, const mwArray& type);

extern LIB_opencrg_CPP_API void MW_CALL_CONV map_wgs2html(int nargout, mwArray& file, const mwArray& llh, const mwArray& file_in1, const mwArray& opts);

extern LIB_opencrg_CPP_API void MW_CALL_CONV sdf_add(int nargout, mwArray& sdf_out, const mwArray& sdf_in, const mwArray& blockname, const mwArray& sdf_block);

extern LIB_opencrg_CPP_API void MW_CALL_CONV sdf_cut(int nargout, mwArray& sdf_block, mwArray& sdf_out, const mwArray& sdf_in, const mwArray& blockname);

extern LIB_opencrg_CPP_API void MW_CALL_CONV smooth_firfilt(int nargout, mwArray& y, const mwArray& x, const mwArray& w, const mwArray& opts);

extern LIB_opencrg_CPP_API void MW_CALL_CONV str_num2strn(int nargout, mwArray& t, const mwArray& x, const mwArray& n);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
