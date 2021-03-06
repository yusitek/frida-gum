/*
 * Copyright (C) 2015 Ole André Vadla Ravnås <ole.andre.ravnas@tillitech.com>
 *
 * Licence: wxWindows Library Licence, Version 3.1
 */

#ifndef __GUM_V8_SYMBOL_H__
#define __GUM_V8_SYMBOL_H__

#include "gumv8core.h"

#include <v8.h>

typedef struct _GumV8Symbol GumV8Symbol;

struct _GumV8Symbol
{
  GumV8Core * core;

  GHashTable * symbols;

  GumPersistent<v8::Object>::type * value;
};

G_GNUC_INTERNAL void _gum_v8_symbol_init (GumV8Symbol * self,
    GumV8Core * core, v8::Handle<v8::ObjectTemplate> scope);
G_GNUC_INTERNAL void _gum_v8_symbol_realize (GumV8Symbol * self);
G_GNUC_INTERNAL void _gum_v8_symbol_dispose (GumV8Symbol * self);
G_GNUC_INTERNAL void _gum_v8_symbol_finalize (GumV8Symbol * self);

#endif
