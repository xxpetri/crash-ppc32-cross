/*
 * Copyright (C) 2010 Red Hat Inc, Steven Rostedt <srostedt@redhat.com>
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License (not later!)
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#ifndef __UTIL_H
#define __UTIL_H

#include <ctype.h>

static inline char *strim(char *string)
{
	char *ret;

	if (!string)
		return NULL;
	while (*string) {
		if (!isspace(*string))
			break;
		string++;
	}
	ret = string;

	string = ret + strlen(ret) - 1;
	while (string > ret) {
		if (!isspace(*string))
			break;
		string--;
	}
	string[1] = 0;

	return ret;
}

static inline int has_text(const char *text)
{
	if (!text)
		return 0;

	while (*text) {
		if (!isspace(*text))
			return 1;
		text++;
	}

	return 0;
}

#endif
