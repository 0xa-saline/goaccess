/**
 * Copyright (C) 2009-2014 by Gerardo Orellana <goaccess@prosoftcorp.com>
 * GoAccess - An Ncurses apache weblog analyzer & interactive viewer
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * A copy of the GNU General Public License is attached to this
 * source distribution for its full text.
 *
 * Visit http://goaccess.prosoftcorp.com for new releases.
 */

#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <stdint.h>

#define MAX_LINE_CONF 512
#define MAX_EXTENSIONS 64

typedef enum
{
  COMMON,
  VCOMMON,
  COMBINED,
  VCOMBINED,
  W3C,
  CLOUDFRONT
} LOGTYPE;

/* predefined log dates */
typedef struct GPreConfDate_
{
  const char *apache;
  const char *w3c;
  const char *cloudfront;
} GPreConfDate;

/* predefined log formats */
typedef struct GPreConfLog_
{
  const char *combined;
  const char *common;
  const char *vcombined;
  const char *vcommon;
  const char *w3c;
  const char *cloudfront;
} GPreConfLog;

typedef struct GConfKeyword_
{
  const unsigned short key_id;
  const char *keyword;
} GConfKeyword;

typedef struct GConf_
{
  char *date_format;
  char *debug_log;
  char *geoip_city_data;
  char *iconfigfile;
  char *ifile;
  char *ignore_host;
  char *log_format;
  char *output_format;
  char *static_files[MAX_EXTENSIONS];
  int append_method;
  int append_protocol;
  int bandwidth;
  int color_scheme;
  int enable_html_resolver;
  int geo_db;
  int ignore_qstr;
  int list_agents;
  int load_conf_dlg;
  int load_global_config;
  int mouse_support;
  int no_color;
  int no_progress;
  int output_html;
  int real_os;
  int serve_usecs;
  int skip_term_resolver;
  int static_file_idx;
  size_t static_file_max_len;

  /* TokyoCabinet */
  char *db_path;
  int64_t xmmap;
  int cache_lcnum;
  int cache_ncnum;
  int compression;
  int keep_db_files;
  int load_from_disk;
  int tune_bnum;
  int tune_lmemb;
  int tune_nmemb;
} GConf;

char *get_selected_date_str (size_t idx);
char *get_selected_format_str (size_t idx);
size_t get_selected_format_idx (void);

extern GConf conf;
extern char *tmp_log_format;
extern char *tmp_date_format;

int parse_conf_file (int *argc, char ***argv);
void free_cmd_args (void);

#endif
