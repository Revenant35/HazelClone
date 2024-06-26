﻿/*! @defgroup mods Modifier key flags
*  @brief Modifier key flags.
 *
 *  See [key input](@ref input_key) for how these are used.
 *
 *  @ingroup input
 *  @{ */

/*! @brief If this bit is set one or more Shift keys were held down.
 *
 *  If this bit is set one or more Shift keys were held down.
 */
#define HZ_MOD_SHIFT           0x0001

/*! @brief If this bit is set one or more Control keys were held down.
 *
 *  If this bit is set one or more Control keys were held down.
 */
#define HZ_MOD_CONTROL         0x0002

/*! @brief If this bit is set one or more Alt keys were held down.
 *
 *  If this bit is set one or more Alt keys were held down.
 */
#define HZ_MOD_ALT             0x0004

/*! @brief If this bit is set one or more Super keys were held down.
 *
 *  If this bit is set one or more Super keys were held down.
 */
#define HZ_MOD_SUPER           0x0008

/*! @brief If this bit is set the Caps Lock key is enabled.
 *
 *  If this bit is set the Caps Lock key is enabled and the @ref
 *  HZ_LOCK_KEY_MODS input mode is set.
 */
#define HZ_MOD_CAPS_LOCK       0x0010

/*! @brief If this bit is set the Num Lock key is enabled.
 *
 *  If this bit is set the Num Lock key is enabled and the @ref
 *  HZ_LOCK_KEY_MODS input mode is set.
 */
#define HZ_MOD_NUM_LOCK        0x0020

/*! @} */