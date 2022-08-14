/************************************************************************************
 ** File: - hal\include\fingerprint.h
 ** OPLUS_FEATURE_FINGERPRINT
 ** Copyright (C), 2008-2020, OPLUS Mobile Comm Corp., Ltd
 **
 ** Description:
 **      HIDL Service entry for fingerprint
 **
 ** Version: 1.0
 ** Date created: 10:58:11,16/08/2020
 ** Author: Chen.ran@Prd.BaseDrv
 ** TAG: BSP.Fingerprint.Basic
 ** ---------------------------Revision History--------------------------------
 **  <author>           <data>            <desc>
 **  Ran.Chen         2019/12/17       modify for  algo_version length
 ************************************************************************************/
#ifndef ANDROID_INCLUDE_HARDWARE_FINGERPRINT_H
#define ANDROID_INCLUDE_HARDWARE_FINGERPRINT_H

#include <hardware/hardware.h>
#include <hardware/hw_auth_token.h>

#define FINGERPRINT_MODULE_API_VERSION_1_0 HARDWARE_MODULE_API_VERSION(1, 0)
#define FINGERPRINT_MODULE_API_VERSION_2_0 HARDWARE_MODULE_API_VERSION(2, 0)
#define FINGERPRINT_MODULE_API_VERSION_2_1 HARDWARE_MODULE_API_VERSION(2, 1)
#define FINGERPRINT_MODULE_API_VERSION_3_0 HARDWARE_MODULE_API_VERSION(3, 0)
#define FINGERPRINT_HARDWARE_MODULE_ID "fingerprint"
#define MAX_ID_LIST_SIZE 5


typedef enum fingerprint_cmd_id {
    FINGERPRINT_CMD_ID_NONE                     = 0,
    // extend func api
    FINGERPRINT_PRODUCT_TEST_CMD_GET_OTP_QRCODE = 31,
    FINGERPRINT_CMD_ID_BASE = 1000,
    FINGERPRINT_CMD_ID_CAMERA = 1001,
    FINGERPRINT_CMD_ID_SIMULATOR_TP = 1002,
    FINGERPRINT_CMD_ID_START_CALI = 1003,
    FINGERPRINT_CMD_ID_END_CALI = 1004,
    FINGERPRINT_CMD_ID_AUTHENTICATE_TYPE = 1005,
    FINGERPRINT_CMD_ID_PAUSE_ENROLL = 1006,
    FINGERPRINT_CMD_ID_CONTINUE_ENROLL = 1007,
    FINGERPRINT_CMD_ID_SET_TOUCHEVENT_LISTENER = 1008,
    FINGERPRINT_CMD_ID_DYNAMICALLY_LOG = 1009,
    FINGERPRINT_CMD_ID_GET_ENROLL_TIMES = 1010,
    FINGERPRINT_CMD_ID_SET_SCREEN_STATE = 1011,
    FINGERPRINT_CMD_ID_GET_ENGINEERING_INFO = 1012,
    FINGERPRINT_CMD_ID_GET_SENSOR_ID = 1013,
    FINGERPRINT_CMD_ID_SIDE_PRESS_ENABLE = 1014,
    FINGERPRINT_CMD_ID_SIDE_SCREEN_STATE = 1015,
    FINGERPRINT_CMD_ID_SIDE_POWER_KEY_PRESSED = 1016,
    FINGERPRINT_CMD_GET_CALIBRATION_FLOW = 1017,
    // calibration
    FINGERPRINT_FACTORY_MESSAGE_DISPLAY     = 2000,
    FINGERPRINT_FACTORY_AUTO_TEST           = 2001,
    FINGERPRINT_FACTORY_QTY_TEST            = 2002,
    FINGERPRINT_FACTORY_GET_ALGO_INFO       = 2003,
    FINGERPRINT_FACTORY_GET_SENSOR_QRCODE   = 2004,
    FINGERPRINT_FACTORY_AGING_TEST          = 2005,
    FINGERPRINT_FACTORY_CALI_FLESH_BOX_TEST = 2006,
    FINGERPRINT_FACTORY_CALI_BLACK_BOX_TEST = 2007,
    FINGERPRINT_FACTORY_CALI_CHART_TEST     = 2008,
    // capture_tool
    FINGERPRINT_CAPTURE_TOOL_GET_IMG        = 3000,
    //auto smoking
    FINGERPRINT_SMOKING_SUPPORT                 = 5000,
    FINGERPRINT_SMOKING_START                   = 5001,
    FINGERPRINT_SMOKING_AUTH_SUCCESS            = 5002,
    FINGERPRINT_SMOKING_AUTH_FAIL               = 5003,
    FINGERPRINT_SMOKING_ENROLL_DEPLICATE        = 5004,
    FINGERPRINT_SMOKING_AUTH_SUCCESS_MUL        = 5005,
    FINGERPRINT_SMOKING_AUTH_FAIL_MUL           = 5006,
    FINGERPRINT_SMOKING_AUTH_SUCCESS_AND_FAIL   = 5007,
    FINGERPRINT_SMOKING_ENROLL_UPPER_LIMIT      = 5008,
    FINGERPRINT_SMOKING_ENROLL_CANCEL           = 5009,
    FINGERPRINT_SMOKING_ENROLL_REPEAT           = 5010,
    FINGERPRINT_SMOKING_ENROLL_LOW_QUALITY      = 5011,
    FINGERPRINT_SMOKING_ENROLL_SAMLL_AREA       = 5012,
    FINGERPRINT_SMOKING_ENROLL_TIMEOUT          = 5013,
    FINGERPRINT_SMOKING_AUTH_LOW_QUALITY        = 5014,
    FINGERPRINT_SMOKING_ENROLL_MANAY_ERR        = 5015,
    FINGERPRINT_SMOKING_END                     = 5016,
} fingerprint_cmd_id_t;

typedef enum fingerprint_callback_cmd_Id {
    FINGERPRINT_CALLBACK_CMD_ID_NONE = 0,
    FINGERPRINT_CALLBACK_CMD_ID_BASE = 1200,
    FINGERPRINT_CALLBACK_CMD_ID_ON_TOUCH_DOWN = 1201,
    FINGERPRINT_CALLBACK_CMD_ID_ON_TOUCH_UP = 1202,
} fingerprint_callback_cmd_Id_t;

typedef enum fingerprint_msg_type {
    FINGERPRINT_ERROR              = -1,
    FINGERPRINT_ACQUIRED           = 1,
    FINGERPRINT_TEMPLATE_ENROLLING = 3,
    FINGERPRINT_TEMPLATE_REMOVED   = 4,
    FINGERPRINT_AUTHENTICATED      = 5,
    FINGERPRINT_GET_IMAGE_QUALITY =
        6,  // This is abandoned in android N, use engineering_info_t instead
    FINGERPRINT_TOUCH_DOWN              = 7,
    FINGERPRINT_TOUCH_UP                = 8,
    FINGERPRINT_MONITOR                 = 9,
    FINGERPRINT_IMAGE_INFO              = 10,
    FINGERPRINT_TEMPLATE_ENUMERATING    = 11,
    ENGINEERING_INFO                    = 12,
    FINGERPRINT_OPTICAL_SENDCMD         = 13,

    FINGERPRINT_HYPNUSDSETACION         = 200,
    FINGERPRINT_BINDCORE                = 201,
    FINGERPRINT_GET_CONFIG_DATA         = 202,
    FINGERPRINT_SETUXTHREAD             = 203,
} fingerprint_msg_type_t;

typedef enum fingerprint_screen_state_type {
    FINGERPRINT_SCREEN_OFF = 0,
    FINGERPRINT_SCREEN_ON  = 1
} fingerprint_screen_state_type_t;

typedef enum fingerprint_touch_state_type {
    FINGERPRINT_TOUCH_DOWN_STATUE = 0,
    FINGERPRINT_TOUCH_UP_STATUE   = 1
} fingerprint_touch_state_type_t;

/*
 * Fingerprint errors are meant to tell the framework to terminate the current operation and ask
 * for the user to correct the situation. These will almost always result in messaging and user
 * interaction to correct the problem.
 *
 * For example, FINGERPRINT_ERROR_CANCELED should follow any acquisition message that results in
 * a situation where the current operation can't continue without user interaction. For example,
 * if the sensor is dirty during enrollment and no further enrollment progress can be made,
 * send FINGERPRINT_ACQUIRED_IMAGER_DIRTY followed by FINGERPRINT_ERROR_CANCELED.
 */
typedef enum fingerprint_error {
    FINGERPRINT_ERROR_HW_UNAVAILABLE = 1, /* The hardware has an error that can't be resolved. */
    FINGERPRINT_ERROR_UNABLE_TO_PROCESS = 2, /* Bad data; operation can't continue */
    FINGERPRINT_ERROR_TIMEOUT = 3, /* The operation has timed out waiting for user input. */
    FINGERPRINT_ERROR_NO_SPACE = 4, /* No space available to store a template */
    FINGERPRINT_ERROR_CANCELED = 5, /* The current operation can't proceed. See above. */
    FINGERPRINT_ERROR_UNABLE_TO_REMOVE = 6, /* fingerprint with given id can't be removed */
    FINGERPRINT_ERROR_LOCKOUT = 7, /* the fingerprint hardware is in lockout due to too many attempts */
    FINGERPRINT_ERROR_VENDOR_BASE = 1000 /* vendor-specific error messages start here */
} fingerprint_error_t;

/*
 * Fingerprint acquisition info is meant as feedback for the current operation.  Anything but
 * FINGERPRINT_ACQUIRED_GOOD will be shown to the user as feedback on how to take action on the
 * current operation. For example, FINGERPRINT_ACQUIRED_IMAGER_DIRTY can be used to tell the user
 * to clean the sensor.  If this will cause the current operation to fail, an additional
 * FINGERPRINT_ERROR_CANCELED can be sent to stop the operation in progress (e.g. enrollment).
 * In general, these messages will result in a "Try again" message.
 */
typedef enum fingerprint_acquired_info {
    FINGERPRINT_ACQUIRED_GOOD = 0,
    FINGERPRINT_ACQUIRED_PARTIAL = 1, /* sensor needs more data, i.e. longer swipe. */
    FINGERPRINT_ACQUIRED_INSUFFICIENT = 2, /* image doesn't contain enough detail for recognition*/
    FINGERPRINT_ACQUIRED_IMAGER_DIRTY = 3, /* sensor needs to be cleaned */
    FINGERPRINT_ACQUIRED_TOO_SLOW = 4, /* mostly swipe-type sensors; not enough data collected */
    FINGERPRINT_ACQUIRED_TOO_FAST = 5, /* for swipe and area sensors; tell user to slow down*/
    FINGERPRINT_ACQUIRED_DETECTED = 6, /* when the finger is first detected. Used to optimize wakeup.
                                        Should be followed by one of the above messages */
    FINGERPRINT_ACQUIRED_VENDOR_BASE = 1000, /* vendor-specific acquisition messages start here */
    FINGERPRINT_ACQUIRED_TOO_SIMILAR = 1001, /* for similar enrolled area*/
    FINGERPRINT_ACQUIRED_ALREADY_ENROLLED = 1002 /*for the same fingerprint as enrolled*/
} fingerprint_acquired_info_t;

typedef struct fingerprint_finger_id {
    uint32_t gid;
    uint32_t fid;
} fingerprint_finger_id_t;

typedef struct fingerprint_enroll {
    fingerprint_finger_id_t finger;
    /* samples_remaining goes from N (no data collected, but N scans needed)
     * to 0 (no more data is needed to build a template). */
    uint32_t samples_remaining;
    uint64_t msg; /* Vendor specific message. Used for user guidance */
} fingerprint_enroll_t;

typedef struct fingerprint_iterator {
    fingerprint_finger_id_t finger;
    uint32_t remaining_templates;
} fingerprint_iterator_t;

typedef fingerprint_iterator_t fingerprint_removed_t;

typedef struct fingerprint_enumerated {
    fingerprint_finger_id_t fingers[MAX_ID_LIST_SIZE];
    uint32_t remaining_templates;
    uint32_t gid;
} fingerprint_enumerated_t;


typedef struct fingerprint_acquired {
    fingerprint_acquired_info_t acquired_info; /* information about the image */
} fingerprint_acquired_t;

typedef struct fingerprint_authenticated {
    fingerprint_finger_id_t finger;
    hw_auth_token_t         hat;
} fingerprint_authenticated_t;

// quality_pass  in fingerprint_quality_t
typedef enum fingerprint_engineering_info_type {
    FINGERPRINT_IMAGE_SNR = 1,
    FINGERPRINT_IMAGE_QUALITY = 2,
    FINGERPRINT_IMAGE_PIXEL = 3,
} fingerprint_engineering_info_type_t;

typedef struct fingerprint_quality {
    uint32_t successed;
    uint32_t image_quality;
    uint32_t quality_pass;
} fingerprint_quality_t;

typedef enum engineering_parameter_group {
    SUCCESSED = 0,
    IMAGE_QUALITY = 1,
    SNR_SUCCESSED = 2,
    IMAGE_SNR = 3,
    BAD_PIXEL_NUM = 4,
    LOCAL_BAD_PIXEL_NUM = 5,
    M_ALL_TILT_ANGLE = 6,
    M_BLOCK_TILT_ANGLE_MAX = 7,
    LOCAL_BIG_PIXEL_NUM = 8,
    QUALITY_PASS = 9
} engineering_parameter_group_t;

typedef struct engineering_info {
    fingerprint_engineering_info_type_t type;
    fingerprint_quality_t quality;
} engineering_info_t;

typedef struct fingerprint_test_cmd
{
    int32_t cmd_id;
    int8_t *result;
    int32_t result_len;
} fingerprint_test_cmd_t;

typedef struct fingerprint_msg {
    fingerprint_msg_type_t type;
    union {
        fingerprint_error_t error;
        fingerprint_enroll_t enroll;
        fingerprint_enumerated_t enumerated;
        fingerprint_removed_t removed;
        fingerprint_acquired_t acquired;
        fingerprint_authenticated_t authenticated;
        engineering_info_t engineering;

        fingerprint_test_cmd_t test;
    } data;
} fingerprint_msg_t;

/* Callback function type */
typedef void (*fingerprint_notify_t)(const fingerprint_msg_t *msg);

/* Synchronous operation */
typedef struct fingerprint_device {
    /**
     * Common methods of the fingerprint device. This *must* be the first member
     * of fingerprint_device as users of this structure will cast a hw_device_t
     * to fingerprint_device pointer in contexts where it's known
     * the hw_device_t references a fingerprint_device.
     */
    struct hw_device_t common;

    /*
     * Client provided callback function to receive notifications.
     * Do not set by hand, use the function above instead.
     */
    fingerprint_notify_t notify;

    /*
     * Set notification callback:
     * Registers a user function that would receive notifications from the HAL
     * The call will block if the HAL state machine is in busy state until HAL
     * leaves the busy state.
     *
     * Function return: 0 if callback function is successfuly registered
     *                  or a negative number in case of error, generally from the errno.h set.
     */
    int (*set_notify)(struct fingerprint_device *dev, fingerprint_notify_t notify);

    /*
     * Fingerprint pre-enroll enroll request:
     * Generates a unique token to upper layers to indicate the start of an enrollment transaction.
     * This token will be wrapped by security for verification and passed to enroll() for
     * verification before enrollment will be allowed. This is to ensure adding a new fingerprint
     * template was preceded by some kind of credential confirmation (e.g. device password).
     *
     * Function return: 0 if function failed
     *                  otherwise, a uint64_t of token
     */
    uint64_t (*pre_enroll)(struct fingerprint_device *dev);

    /*
     * Fingerprint enroll request:
     * Switches the HAL state machine to collect and store a new fingerprint
     * template. Switches back as soon as enroll is complete
     * (fingerprint_msg.type == FINGERPRINT_TEMPLATE_ENROLLING &&
     *  fingerprint_msg.data.enroll.samples_remaining == 0)
     * or after timeout_sec seconds.
     * The fingerprint template will be assigned to the group gid. User has a choice
     * to supply the gid or set it to 0 in which case a unique group id will be generated.
     *
     * Function return: 0 if enrollment process can be successfully started
     *                  or a negative number in case of error, generally from the errno.h set.
     *                  A notify() function may be called indicating the error condition.
     */
    int (*enroll)(struct fingerprint_device *dev, const hw_auth_token_t *hat,
                    uint32_t gid, uint32_t timeout_sec);

    /*
     * Finishes the enroll operation and invalidates the pre_enroll() generated challenge.
     * This will be called at the end of a multi-finger enrollment session to indicate
     * that no more fingers will be added.
     *
     * Function return: 0 if the request is accepted
     *                  or a negative number in case of error, generally from the errno.h set.
     */
    int (*post_enroll)(struct fingerprint_device *dev);

    /*
     * get_authenticator_id:
     * Returns a token associated with the current fingerprint set. This value will
     * change whenever a new fingerprint is enrolled, thus creating a new fingerprint
     * set.
     *
     * Function return: current authenticator id or 0 if function failed.
     */
    uint64_t (*get_authenticator_id)(struct fingerprint_device *dev);

    /*
     * Cancel pending enroll or authenticate, sending FINGERPRINT_ERROR_CANCELED
     * to all running clients. Switches the HAL state machine back to the idle state.
     * Unlike enroll_done() doesn't invalidate the pre_enroll() challenge.
     *
     * Function return: 0 if cancel request is accepted
     *                  or a negative number in case of error, generally from the errno.h set.
     */
    int (*cancel)(struct fingerprint_device *dev);

    /*
     * Enumerate all the fingerprint templates found in the directory set by
     * set_active_group()
     * For each template found a notify() will be called with:
     * fingerprint_msg.type == FINGERPRINT_TEMPLATE_ENUMERATED
     * fingerprint_msg.data.enumerated.finger indicating a template id
     * fingerprint_msg.data.enumerated.remaining_templates indicating how many more
     * enumeration messages to expect.
     * Note: If there are no fingerprints, then this should return 0 and the first fingerprint
     *                  enumerated should have fingerid=0 and remaining=0
     * Function return: 0 if enumerate request is accepted
     *                  or a negative number in case of error, generally from the errno.h set.
     */
    int (*enumerate)(struct fingerprint_device *dev);

    /*
     * Fingerprint remove request:
     * Deletes a fingerprint template.
     * Works only within the path set by set_active_group().
     * The fid parameter can be used as a widcard:
     *   * fid == 0 -- delete all the templates in the group.
     *   * fid != 0 -- delete this specific template from the group.
     * For each template found a notify() will be called with:
     * fingerprint_msg.type == FINGERPRINT_TEMPLATE_REMOVED
     * fingerprint_msg.data.removed.finger indicating a template id deleted
     * fingerprint_msg.data.removed.remaining_templates indicating how many more
     * templates will be deleted by this operation.
     *
     * Function return: 0 if fingerprint template(s) can be successfully deleted
     *                  or a negative number in case of error, generally from the errno.h set.
     */
    int (*remove)(struct fingerprint_device *dev, uint32_t gid, uint32_t fid);

    /*
     * Restricts the HAL operation to a set of fingerprints belonging to a
     * group provided.
     * The caller must provide a path to a storage location within the user's
     * data directory.
     *
     * Function return: 0 on success
     *                  or a negative number in case of error, generally from the errno.h set.
     */
    int (*set_active_group)(struct fingerprint_device *dev, uint32_t gid,
                            const char *store_path);

    /*
     * Authenticates an operation identifed by operation_id
     *
     * Function return: 0 on success
     *                  or a negative number in case of error, generally from the errno.h set.
     */
    int (*authenticate)(struct fingerprint_device *dev, uint64_t operation_id, uint32_t gid);

    /* Reserved for backward binary compatibility */
    void *reserved[4];
} fingerprint_device_t;

typedef struct fingerprint_module {
    /**
     * Common methods of the fingerprint module. This *must* be the first member
     * of fingerprint_module as users of this structure will cast a hw_module_t
     * to fingerprint_module pointer in contexts where it's known
     * the hw_module_t references a fingerprint_module.
     */
    struct hw_module_t common;
} fingerprint_module_t;

#endif  /* ANDROID_INCLUDE_HARDWARE_FINGERPRINT_H */