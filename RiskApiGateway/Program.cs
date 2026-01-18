var builder = WebApplication.CreateBuilder(args);

// ================= SERVICES =================
builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

// ================= APP ======================
var app = builder.Build();

// ================= PIPELINE =================
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

// HTTP only (no HTTPS redirect for now)
// app.UseHttpsRedirection();

// ================= ROUTING ==================
app.MapControllers();

// ================= RUN ======================
app.Run();