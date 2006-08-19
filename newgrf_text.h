/* $Id$ */
#ifndef NEWGRF_TEXT_H
#define NEWGRF_TEXT_H

/** @file
 * Header of Action 04 "universal holder" structure and functions
 */

StringID AddGRFString(uint32 grfid, uint16 stringid, byte langid, bool new_scheme, const char *text_to_add, StringID def_string);
StringID GetGRFStringID(uint32 grfid, uint16 stringid);
char *GetGRFString(char *buff, uint16 stringid);
void CleanUpStrings(void);
void SetCurrentGrfLangID(const char *iso_name);

#endif /* NEWGRF_TEXT_H */
