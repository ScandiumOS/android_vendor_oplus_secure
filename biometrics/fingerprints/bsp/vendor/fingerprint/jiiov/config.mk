#ANC_CONFIG_DEBUG=TRUE


ifeq ($(ANC_CONFIG_REE), TRUE)
ANC_CONFIG_LOCAL_TEE_PLATFORM=REE
else
ifeq ($(call is-vendor-board-platform,QCOM), true)
ANC_CONFIG_LOCAL_TEE_PLATFORM=QSEE
ANC_CONFIG_LOCAL_QSEE_VERSION=5_0
else
ANC_CONFIG_LOCAL_TEE_PLATFORM=TRUSTONIC
endif
endif

ANC_CONFIG_TA_DEFAULT_PATH=/odm/vendor/firmware
#ANC_CONFIG_TA_DEFAULT_NAME=ancap32
ANC_CONFIG_TA_DEFAULT_NAME=ancap64
ANC_CONFIG_KEYMASTER_TA_PATH=
ANC_CONFIG_KEYMASTER_TA_NAME=keymaster64

ANC_CONFIG_GET_IMAGE_FROM_HAL=TRUE
ANC_CONFIG_GET_IMAGE_FROM_TA=TRUE
ANC_CONFIG_GET_SENSOR_IMAGE=TRUE
ANC_CONFIG_PADDING_INFO_IN_IMAGE_BUFFER=TRUE

ANC_CONFIG_USE_SLEEP_REPLACE_WAIT_TP_EVENT=FALSE
ANC_CONFIG_USE_HW_AUTH_TOKEN=TRUE
ANC_CONFIG_QUICKLY_PICK_UP_FINGER=TRUE
ANC_CONFIG_QCOM_SPI_BIT_SHIFT=FALSE

ifeq ($(TARGET_BUILD_VARIANT), user)
ANC_CONFIG_SAVE_FILE=FALSE
else
ANC_CONFIG_SAVE_FILE=TRUE
endif

ifeq ($(TARGET_BUILD_VARIANT), user)
ANC_CONFIG_DEBUG=FALSE
else
ANC_CONFIG_DEBUG=TRUE
endif


ANC_CONFIG_ALGORITHM_STUDY_SWITCH=FALSE

ANC_CONFIG_USE_VIRTUAL_SENSOR=FALSE
ANC_CONFIG_LOAD_BASE_IMAGE_FROM_RAW_FILE=FALSE
ANC_CONFIG_WAIT_HBM=TRUE
ANC_CONFIG_HBM_PATH=/sys/kernel/oplus_display/hbm

ANC_CONFIG_ANDROID_VERSION=ANDROID_S
ANC_CONFIG_HEART_BEAT_EXPOSURE_TIME=16325

ANC_CONFIG_CUSTOMER=oplus