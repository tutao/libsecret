/* GSecret - GLib wrapper for Secret Service
 *
 * Copyright 2011 Collabora Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2 of the licence or (at
 * your option) any later version.
 *
 * See the included COPYING file for more information.
 */

#include "config.h"

#include "gsecret-private.h"
#include "gsecret-types.h"

#include <string.h>

GQuark
gsecret_error_get_quark (void)
{
	static volatile gsize initialized = 0;
	static GQuark quark = 0;

	if (g_once_init_enter (&initialized)) {
		quark = g_quark_from_static_string ("gsecret-error");
		g_once_init_leave (&initialized, 1);
	}

	return quark;
}

gchar *
_gsecret_util_parent_path (const gchar *path)
{
	const gchar *pos;

	g_return_val_if_fail (path != NULL, NULL);

	pos = strrchr (path, '/');
	g_return_val_if_fail (pos != NULL, NULL);
	g_return_val_if_fail (pos != path, NULL);

	pos--;
	return g_strndup (path, pos - path);
}
