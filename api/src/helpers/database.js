import Sequelize from 'sequelize';

const sequelize = new Sequelize(
    process.env.DB_NAME,
    process.env.DB_USER,
    process.env.DB_PASSWORD,
    {
        host: process.env.DB_HOST,
        dialect: 'postgres',
    },
);

const models = {
    User: sequelize.import('../models/user'),
    Message: sequelize.import('../models/message'),
    Agent: sequelize.import('../models/agent'),
};

Object.keys(models).forEach(key => {
    if ('associate' in models[key]) {
        models[key].associate(models);
    }
});


export { sequelize };
export default models;