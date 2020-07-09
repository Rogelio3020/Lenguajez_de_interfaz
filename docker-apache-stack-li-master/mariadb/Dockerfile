ARG MYSQL_VERSION=""
FROM  bitnami/mariadb:${MYSQL_VERSION:-latest}
COPY config/my.cnf /opt/bitnami/mariadb/conf/
USER root
RUN chmod 444 /opt/bitnami/mariadb/conf/my.cnf 