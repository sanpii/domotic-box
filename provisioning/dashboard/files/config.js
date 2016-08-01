'use strict';

angular.module('config', [])
    .constant('MQTT_HOST', 'dashboard.homecomputing.fr')
    .constant('MQTT_PORT', 9002)
    .constant('MQTT_USER', '')
    .constant('MQTT_PASSWORD', '')
    .constant('PG_URL', 'https://pg.example.org')
    .constant('PG_DB', 'domotic')
    .constant('PG_USER', 'vagrant')
    .constant('PG_PASSWORD', 'vagrant');
