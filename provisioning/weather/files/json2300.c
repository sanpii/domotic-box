#include "rw2300.h"

int main(int argc, char *argv[])
{
    WEATHERSTATION ws2300;
    const char *directions[]= {"N","NNE","NE","ENE","E","ESE","SE","SSE",
                               "S","SSW","SW","WSW","W","WNW","NW","NNW"};
    double winddir[6];
    int tempint;
    char tendency[15];
    char forecast[15];
    struct config_type config;

    get_configuration(&config, argv[1]);

    ws2300 = open_weatherstation(config.serial_device_name);

    printf("{");

    printf("\"temperature_indoor\":%.1f,", temperature_indoor(ws2300, config.temperature_conv));
    printf("\"temperature_outdoor\":%.1f,", temperature_outdoor(ws2300, config.temperature_conv));
    printf("\"dewpoint\":%.1f,", dewpoint(ws2300, config.temperature_conv));
    printf("\"humidity_indoor\":%d,", humidity_indoor(ws2300));
    printf("\"humidity_outdoor\":%d,", humidity_outdoor(ws2300));
    printf("\"wind_all\":%.1f,", wind_all(ws2300, config.wind_speed_conv_factor, &tempint, winddir));
    printf("\"winddir\":%.1f,", winddir[0]);
    printf("\"directions\":\"%s\",", directions[tempint]);
    printf("\"windchill\":%.1f,", windchill(ws2300, config.temperature_conv));
    printf("\"rain_1h\":%.1f,", rain_1h(ws2300, config.rain_conv_factor));
    printf("\"rain_24h\":%.1f,", rain_24h(ws2300, config.rain_conv_factor));
    printf("\"rain_total\":%.1f,", rain_total(ws2300, config.rain_conv_factor));
    printf("\"rel_pressure\":%.1f,", rel_pressure(ws2300, config.pressure_conv_factor));
    tendency_forecast(ws2300, tendency, forecast);
    printf("\"tendency\":\"%s\",", tendency);
    printf("\"forecast\":\"%s\"", forecast);

    printf("}");

    close_weatherstation(ws2300);

    return 0;
}
