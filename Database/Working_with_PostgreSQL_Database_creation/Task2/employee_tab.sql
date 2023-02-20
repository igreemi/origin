create table if not exists employee_name(
id serial primary key,
name varchar(120) not null
);

create table if not exists department(
id serial primary key,
department varchar(120) not null
);

create table if not exists boss(
id serial primary key,
name_id integer not null references employee_name(id),
department_id integer not null references department(id)
);

create table if not exists employee(
id serial primary key,
name_id integer not null references employee_name(id),
department_id integer not null references department(id),
boss integer not null references boss(id)
);